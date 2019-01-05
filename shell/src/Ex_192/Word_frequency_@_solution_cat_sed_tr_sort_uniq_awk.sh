# references:
#       https://leetcode.com/problems/word-frequency/discuss/197037/1-line-solution
#       https://superuser.com/questions/59833/how-to-count-the-number-of-occurrences-of-each-word-in-a-file


# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | sed 's/ /\n/g' | sed '/^$/d' | tr '[:upper:]' '[:lower:]' | sort | uniq -c | sort -nr | awk '{print $2" "$1}'
