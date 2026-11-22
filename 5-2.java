public class BinarySearchScaffolding {

    public static int binarySearch(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] sortedArray = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};

        runTest(sortedArray, 23, 5);
        runTest(sortedArray, 2,  0);
        runTest(sortedArray, 91, 9);
        runTest(sortedArray, 42, -1);
    }

    public static void runTest(int[] arr, int target, int expected) {
        int result = binarySearch(arr, target);
        System.out.println("Target: " + target + " | Expected: " + expected + " | Actual: " + result);
        
        if (result == expected) {
            System.out.println(" PASS\n");
        } else {
            System.out.println(" FAIL\n");
        }
    }
}
