class Solution {
public:
    int minOperations(vector<int>& values) {
    int n = values.size();

    // Find position of minimum element.
    int p = min_element(values.begin(), values.end()) - values.begin();


    // --------------------------------------------------
    // Check forward orientation
    // values[p], values[p+1], ..., cyclically
    // --------------------------------------------------

    bool forward = true;

    for (int k = 0; k < n - 1; k++) {

        int curr = values[(p + k) % n];
        int next = values[(p + k + 1) % n];

        if (curr > next) {
            forward = false;
            break;
        }
    }


    // --------------------------------------------------
    // Check backward orientation
    // values[p], values[p-1], ..., cyclically
    // --------------------------------------------------

    bool backward = true;

    for (int k = 0; k < n - 1; k++) {

        int curr = values[(p - k + n) % n];
        int next = values[(p - k - 1 + n) % n];

        if (curr > next) {
            backward = false;
            break;
        }
    }


    // --------------------------------------------------
    // Calculate cost
    // --------------------------------------------------

    int answer = INT_MAX;


    // Forward target
    if (forward) {

        // Either:
        //   p rotations directly
        //
        // or:
        //   n-p rotations in the opposite direction
        //   using Flip + Rotate + Flip
        //
        // Cost = n-p+2

        int costForward = min(p, n - p + 2);

        answer = min(answer, costForward);
    }


    // Backward target
    if (backward) {

        p = n - p -1;

       int costBackward = min(1 + (n-p), 1 + p);

        answer = min(answer, costBackward);
    }


    if (answer == INT_MAX) {
        return -1;
    }

    return answer;
        
    }
};