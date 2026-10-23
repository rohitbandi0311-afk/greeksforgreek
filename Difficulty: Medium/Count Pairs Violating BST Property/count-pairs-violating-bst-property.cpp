class Solution {
private:
    int merge(vector<int>& arr, int temp[], int left, int mid, int right) {
        int i = left;    // Starting index for left subarray
        int j = mid + 1; // Starting index for right subarray
        int k = left;    // Starting index to be sorted
        int invCount = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // There are (mid - i + 1) elements remaining in the left subarray
                // all of which are greater than arr[j]
                temp[k++] = arr[j++];
                invCount += (mid - i + 1);
            }
        }

        // Copy the remaining elements of left subarray
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy the remaining elements of right subarray
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy back the sorted elements into the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return invCount;
    }

    int mergeSort(vector<int>& arr, int temp[], int left, int right) {
        int mid, invCount = 0;
        if (right > left) {
            mid = (left + right) / 2;

            invCount += mergeSort(arr, temp, left, mid);
            invCount += mergeSort(arr, temp, mid + 1, right);

            invCount += merge(arr, temp, left, mid, right);
        }
        return invCount;
    }

    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

public:
    int pairsViolatingBST(Node* root) {
        // Step 1: Get the in-order traversal of the binary tree
        vector<int>& arr = *(new vector<int>());
        inorder(root, arr);

        int n = arr.size();
        int* temp = new int[n];

        // Step 2: Count inversions in the in-order array using Merge Sort
        int totalViolations = mergeSort(arr, temp, 0, n - 1);

        delete[] temp;
        return totalViolations;
    }
};