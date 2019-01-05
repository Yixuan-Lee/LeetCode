# references:
#       (couldn't find)


# Read from the file words.txt and output the word frequency list to stdout.
perl -0777 -lape's/ /\n/g' words.txt | sed '/^$/d' | sort | uniq -c | sort -nr | awk '{print $2" "$1}'
