class Solution {
public:
    int bestClosingTime(string customers) {
        int best_hour = 0;
        int current_penalty = 0;

        // 1. Calculate the initial penalty if the shop closes at hour 0 (all 'Y's count as penalty)
        for (char c : customers) {
            if (c == 'Y') current_penalty++;
        }

        int min_penalty = current_penalty;

        // 2. Iterate through each hour to update the penalty dynamically
        for (int i = 0; i < customers.length(); i++) {
            if (customers[i] == 'Y') {
                current_penalty--; // 'Y' shifts to open shop area -> penalty drops
            } else {
                current_penalty++; // 'N' shifts to open shop area -> penalty rises
            }
            
            // Update the earliest hour if a strictly smaller penalty is found
            if (current_penalty < min_penalty) {
                min_penalty = current_penalty;
                best_hour = i + 1;
            }
        }

        return best_hour;
    }
};
