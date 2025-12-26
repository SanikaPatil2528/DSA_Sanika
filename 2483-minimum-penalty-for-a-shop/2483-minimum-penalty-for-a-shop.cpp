class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        // Initial penalty: shop closed all day -> count of 'Y'
        int penalty = 0;
        for (char c : customers) {
            if (c == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHour = 0;

        // Move closing hour from left to right
        for (int j = 0; j < n; j++) {
            if (customers[j] == 'Y') {
                penalty--;   // Y moves from closed to open
            } else {
                penalty++;   // N moves from closed to open
            }

            // j+1 is the new closing hour
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = j + 1;
            }
        }

        return bestHour;
    }
};