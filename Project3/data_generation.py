import csv
from faker import Faker
import random
from datetime import datetime, timedelta

fake = Faker()
Faker.seed(0)  

cities = ['London', 'Phuket', 'Bali', 'New York', 'Tokyo', 'Paris', 'Sydney', 'Rio de Janeiro', 'Amsterdam', 'Dubai', 'Cancun', 'Barcelona', 'Honolulu', 'Berlin', 'Marrakech', 'Edinburgh', 'Vancouver', 'Seoul', 'Auckland', 'Rome', 'Porto', 'Santorini', 'Cape Town', 'Cartagena', 'Copenhagen', 'Salzburg', 'Hoi An', 'Reykjavik', 'Kathmandu', 'Luxembourg City', 'Dublin', 'Cairo']
months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
genders = ['Male', 'Female']
accomodations = ['Hotel', 'Resort', 'Airbnb', 'Villa', 'Vacation Rental', 'Hostel', 'Eco-Lodge']

#generate random data
def generate_row():
    destinations = random.choice(cities)
    month = random.choice(months)
    duration = round(random.randint(5, 18))
    age = round(random.randint(18, 65))
    gender = random.choice(genders)
    accomodation = random.choice(accomodations)
    budget = round(random.uniform(1000, 50000), 2)
    return [destinations, month, duration, age, gender, accomodation, budget]

num_rows = 20000

with open('travel_data.csv', 'w', newline='') as file:
    writer = csv.writer(file)

    writer.writerow(['Destination', 'Month', 'Duration', 'Age', 'Gender', 'Accomodation Style', 'Budget'])

    for _ in range(num_rows):
        row = generate_row()
        writer.writerow(row)

print("CSV file created successfully.")
