/**
 * Time complexity: O(nlogn)
 * Space complexity: O(1)
 */

class Solution {
    public int[][] merge(int[][] intervals) {
        // check the input
        if (intervals.length == 0)
            return intervals;

        // sort
        // this can be switched to lamgdas
        Arrays.sort(intervals, new Comparator<int[]>(){
           public int compare(int[] o1, int[] o2) {
               return o1[0] - o2[0];
           }
        });

        // output
        ArrayList<int[]> result = new ArrayList<>();

        int[] current = intervals[0];
        for (int i = 1; i < intervals.length; i++) {
            if (current[1] >= intervals[i][0]) {
                // overlap, then merge
                current = merge(current, intervals[i]);
            } else {
                // no overlap
                result.add(current);
                // update current
                current = intervals[i];
            }
        }
        result.add(current);

        return result.toArray(new int[result.size()][]);
    }

    private int[] merge(int[] in1, int[] in2) {
        int[] result = new int[2];
        result[0] = Math.min(in1[0], in2[0]);
        result[1] = Math.max(in1[1], in2[1]);
        return result;
    }
}
