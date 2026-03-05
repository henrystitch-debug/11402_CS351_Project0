class TwoSum {
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
public static void main(String[] args) {

    int[] numbers = {1,2,3,4,5,6};
    int target = 8; 

    int[] result = twoSum(numbers, target);
    System.out.println("Indices: " + result[0] + ", " + result[1]);



}
}