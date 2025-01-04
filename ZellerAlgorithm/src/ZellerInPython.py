def get_day_of_week(d, m, y):
    # Adjust month and year
    if m < 3:
        y -= 1
        m += 12
    else:
        m += 1

    # Split the year into century and year of century
    yc = y // 100
    yd = y % 100

    # Calculate h using Zeller's algorithm
    h = (d + (13 * (m + 1)) // 5 + yd + yd // 4 + yc // 4 - 2 * yc) % 7

    # Convert h to the day of the week
    days_of_week = ["Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]
    return days_of_week[h]

# Example usage: date January 4, 2025
d = 4  # Day of the month
m = 1  # Month (January = 1, February = 2, ..., December = 12)
y = 2025  # Year

day_of_week = get_day_of_week(d, m, y)
print("Day of the week:", day_of_week)
