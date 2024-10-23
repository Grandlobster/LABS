import pandas as pd

# Function to load and match data from two CSV files
def match_parties_and_companies(party_file, company_file):
    # Load data from the CSV files
    party_df = pd.read_csv(party_file)
    company_df = pd.read_csv(company_file)

    # Check column names
    print("Party DataFrame columns before cleaning:", party_df.columns.tolist())
    print("Company DataFrame columns before cleaning:", company_df.columns.tolist())

    # Clean column names
    party_df.columns = party_df.columns.str.strip()
    company_df.columns = company_df.columns.str.replace('\r', '', regex=False).str.strip()

    # Verify column names after cleaning
    print("Party DataFrame columns after cleaning:", party_df.columns.tolist())
    print("Company DataFrame columns after cleaning:", company_df.columns.tolist())

    # Check if necessary columns exist
    if 'Denomination' not in party_df.columns or 'Denomination' not in company_df.columns:
        raise KeyError("The 'Denomination' column is missing from one of the DataFrames.")
    
    if 'Name of the Political Party' not in company_df.columns:
        raise KeyError("The 'Name of the Political Party' column is missing from the company DataFrame.")
    
    if 'Purchaser Name' not in party_df.columns:
        raise KeyError("The 'Purchaser Name' column is missing from the party DataFrame.")

    # Convert the 'Denomination' column to numeric (removing commas if necessary)
    party_df['Denomination'] = party_df['Denomination'].replace(',', '', regex=True).astype(float)
    company_df['Denomination'] = company_df['Denomination'].replace(',', '', regex=True).astype(float)

    # Sum denominations by political party and purchaser
    party_totals = company_df.groupby('Name of the Political Party')['Denomination'].sum().reset_index()
    company_totals = party_df.groupby('Purchaser Name')['Denomination'].sum().reset_index()

    # Merge the two DataFrames to find matches
    merged_df = pd.merge(party_totals, company_totals, how='cross', suffixes=('_Party', '_Purchaser'))

    # Find matches where the denominations are equal
    matches = merged_df[merged_df['Denomination_Party'] == merged_df['Denomination_Purchaser']]

    # Save the matching results to a CSV file named 'sep.csv'
    matches.to_csv('sep.csv', sep=',', index=False)
    print("Matching results saved to 'sep.csv'.")

# Example usage:
party_file = 'purchaser_bonds1.csv'  # Path to the political party CSV file
company_file = 'party_bonds2.csv'     # Path to the company CSV file

# Run the matching function
try:
    match_parties_and_companies(party_file, company_file)
except Exception as e:
    print(f"An error occurred: {e}")

