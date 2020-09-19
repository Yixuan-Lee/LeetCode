/**
 * Time complexity:
 * Space complexity:
 */

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();

        recursive(result, "", n, 0, 0);
        return result;
    }

    public void recursive(List<String> result, String temp, int n, int open, int close) {
        // temp records the current string

        // base case
        if (close == n) {
            result.add(temp);
            return;
        }

        // add an (
        if (open < n)
            recursive(result, temp + "(", n, open + 1, close);

        // add a )
        if (close < open)
            recursive(result, temp + ")", n, open, close + 1);
    }
}