public class ZellersAlgorithm {

    public static String getDayOfWeek(int d, int m, int y) {
        // Adjust month and year
        if (m < 3) {
            y -= 1;
            m += 12;
        } else {
            m += 1;
        }

        // Split the year into century and year of century
        int yc = y / 100;
        int yd = y % 100;

        // Calculate h using Zeller's algorithm
        int h = (d + (13 * (m + 1)) / 5 + yd + yd / 4 + yc / 4 - 2 * yc) % 7;

        // Convert h to the day of the week
        String[] daysOfWeek = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        return daysOfWeek[h];
    }

    public static void main(String[] args) {
        // Example usage: date January 4, 2025
        int d = 18; // Day of the month
        int m = 2; // Month (January = 1, February = 2, ..., December = 12)
        int y = 2025; // Year

        String dayOfWeek = getDayOfWeek(d, m, y);
        System.out.println("Day of the week: " + dayOfWeek);
    }
}
