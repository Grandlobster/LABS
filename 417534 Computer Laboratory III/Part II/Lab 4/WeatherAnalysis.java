import java.io.IOException;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;

public class WeatherAnalysis {

    // 1. THE MAPPER: Reads the file line by line
    public static class MyMapper extends Mapper<LongWritable, Text, Text, IntWritable> {
        public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
            
            String row = value.toString();
            
            // Skip the header row (the names of the columns)
            if (row.contains("date_time")) {
                return;
            }

            // Split the row by comma to get individual columns
            String[] columns = row.split(",");

            // Extract the year (first 4 characters of the date_time column at index 0)
            String myYear = columns[0].substring(0, 4);

            // Get the temperature (from index 20) and turn it into a number
            int currentTemp = Integer.parseInt(columns[20]);

            // Send (Year, Temperature) to the Reducer
            context.write(new Text(myYear), new IntWritable(currentTemp));
        }
    }

    // 2. THE REDUCER: Finds the Max and Min for each year
    public static class MyReducer extends Reducer<Text, IntWritable, Text, Text> {
        public void reduce(Text myYear, Iterable<IntWritable> allTemps, Context context) throws IOException, InterruptedException {
            
            int highest = -999; // Start very low
            int lowest = 999;   // Start very high

            // Look at every temperature sent for this specific year
            for (IntWritable tempValue : allTemps) {
                int score = tempValue.get();
                
                if (score > highest) {
                    highest = score;
                }
                if (score < lowest) {
                    lowest = score;
                }
            }

            // Create a nice looking message
            String result = "Hottest: " + highest + "C, Coolest: " + lowest + "C";
            
            // Output the final answer for this year
            context.write(myYear, new Text(result));
        }
    }

    // 3. THE DRIVER: This starts the whole engine
    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job myJob = Job.getInstance(conf, "Weather Task");

        myJob.setJarByClass(WeatherAnalysis.class);
        myJob.setMapperClass(MyMapper.class);
        myJob.setReducerClass(MyReducer.class);

        // Tell Hadoop what type of data the Mapper sends out
        myJob.setMapOutputKeyClass(Text.class);
        myJob.setMapOutputValueClass(IntWritable.class);

        // Set the input and output folders
        FileInputFormat.addInputPath(myJob, new Path(args[0]));
        FileOutputFormat.setOutputPath(myJob, new Path(args[1]));

        System.exit(myJob.waitForCompletion(true) ? 0 : 1);
    }
}
