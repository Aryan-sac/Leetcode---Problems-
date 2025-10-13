class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        List<String> ans = new ArrayList<>();
        String current = "";
        allWays(s, res, ans, current, 0);
        return res;
    }

    public static void allWays(String s, List<List<String>> res, List<String> ans, String current, int idx) {
        if (idx == s.length()) {
            if (current.length() == 0) {
                res.add(new ArrayList<>(ans));
            }
            return;
        }

        current += s.charAt(idx);
        if (isValidPalindrome(current)) {
            ans.add(current);
            allWays(s, res, ans, "", idx + 1);
            ans.remove(ans.size() - 1);
        }

        allWays(s, res, ans, current, idx + 1);
    }

    public static boolean isValidPalindrome(String str) {
        int l = 0, r = str.length() - 1;
        while (l < r) {
            if (str.charAt(l++) != str.charAt(r--)) return false;
        }
        return true;
    }
}