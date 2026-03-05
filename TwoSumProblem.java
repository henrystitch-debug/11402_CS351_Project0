public class TwoSumProblem {
static int[] twoSum(int[] nums, int target) {

    int no1 = 0;
    int no2 = 0;
    for(int i = 0; i < nums.length; i++){
        for(int j = 0; j < nums.length; j++){
            if(nums[i] + nums[j] == target){
                no1 = i;
                no2 = j;
            }
        }
    }
    return new int[]{no1, no2};
}

static int[] twoSumHashtable(int[] nums, int target) {
    java.util.HashMap<Integer, Integer> map = new java.util.HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (map.containsKey(complement)) {
            return new int[]{map.get(complement), i};
        }
        map.put(nums[i], i);
    }
    return new int[]{};
}

public static void main(String[] args) {

    int[] numbers = {1,2,3,4,5,6};
    int target = 8; 

    int[] result = twoSum(numbers, target);
    System.out.println("Indices: " + result[0] + ", " + result[1]);

    int[] result2 = twoSumHashtable(numbers, target);
    System.out.println("Indices: " + result2[0] + ", " + result2[1]);



}

}
