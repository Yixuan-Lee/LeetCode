/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution {
    public String minRemoveToMakeValid(String s) {
        StringBuilder st = new StringBuilder();

        // step 1: set a counter
        int open_counter = 0;

        // step 2: scan the string
        for (char c : s.toCharArray()) {
            if (c == '(') {
                open_counter++;
            } else if (c == ')') {
                // make sure before ), there is an opening parentheses
                if (open_counter == 0)
                    continue;
                open_counter--;
            }
            st.append(c);
        }

        // step 3: scaning from end to the beginning
        StringBuilder result = new StringBuilder();
        for (int i = st.length() - 1; i >= 0; --i) {
            if (st.charAt(i) == '(' && open_counter != 0) {
                open_counter--;
                continue;
            }
            result.append(st.charAt(i));
        }
        return result.reverse().toString();
    }
}