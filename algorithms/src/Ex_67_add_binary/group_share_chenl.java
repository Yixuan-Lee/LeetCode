/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

class Solution {
    public String addBinary(String a, String b) {
        StringBuilder st = new StringBuilder();

        // define 2 indices and carry
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // loop through strings a and b
        while (i >= 0 || j >= 0) {
            // sum of current index
            int sum = carry;
            if (i >= 0)
                sum += a.charAt(i) - '0';
            if (j >= 0)
                sum += b.charAt(j) - '0';

            // possible sum values:
            //  0: none of the threes is 1
            //  1: one of the threes is 1
            //  2: two of the threes are 1
            //  3: carry = 1, a.charAt(i) = 1, b.charAt(j) = 1
            st.append(sum % 2);

            // update the carry
            carry = sum / 2;

            i--;
            j--;
        }

        // consider the final carry
        if (carry == 1)
            st.append(1);

        return st.reverse().toString();
    }
}