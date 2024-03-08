// Lucas Martin Garcia

void miniMaxSum(vector<int> arr) {
    long max = 0, min, current;
    vector<int> maxV, minV;
    for (int i = 1; i < arr.size(); ++i) {
        max += arr[i];
    }
    min = max;

    for (int i = 1; i < arr.size(); ++i) {
        current = 0;
        for (int j = 0; j < arr.size(); ++j) {
            if (i != j) {
                current += arr[j];
            }
        }
        if (current > max) max = current;
        if (current < min) min = current;
    }
    cout << min << " " << max << endl;
}