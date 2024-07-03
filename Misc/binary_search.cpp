int binary_search(int arr[], int size);

int main() {}

int binary_search(int arr[], int size, int item) {
    bool found;
    int low = 0, high = size - 1, mid, position = -1;

    while (!found && low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == item) {
            found = true;
            position = mid;
        } else if (arr[mid] > item) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return mid;
}
