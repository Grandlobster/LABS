import pandas as pd

# Function to load and match data from two CSV files
def match_parties_and_companies(party_file, company_file):
    # Load data from the CSV files
    party_df = pd.read_csv(party_file)
    company_df = pd.read_csv(company_file)

    # Convert the 'Denomination' column to numeric (removing commas if necessary)
    party_df['Denomination'] = party_df['Denomination'].replace(',', '', regex=True).astype(float)
    company_df['Denomination'] = company_df['Denomination'].replace(',', '', regex=True).astype(float)

    # Sum denominations by political party and purchaser
    party_totals = party_df.groupby('Name of the Political Party')['Denomination'].sum().reset_index()
    company_totals = company_df.groupby('Purchaser Name')['Denomination'].sum().reset_index()

    # Merge the two DataFrames to find matches
    merged_df = pd.merge(party_totals, company_totals, how='cross', suffixes=('_Party', '_Purchaser'))

    # Find matches where the denominations are equal
    matches = merged_df[merged_df['Denomination_Party'] == merged_df['Denomination_Purchaser']]

    return matches[['Name of the Political Party', 'Purchaser Name', 'Denomination_Party', 'Denomination_Purchaser']]

# Example usage:
party_file = 'purchaser_bonds1.csv'   # Path to the political party CSV file
company_file = 'party_bonds2.csv'      # Path to the company CSV file
matching_results = match_parties_and_companies(party_file, company_file)

# Save the matching results to a new CSV file
output_file = 'matching_results.csv'  # Specify the output file name
matching_results.to_csv(output_file, index=False)

# Print the matching results
print(matching_results)

