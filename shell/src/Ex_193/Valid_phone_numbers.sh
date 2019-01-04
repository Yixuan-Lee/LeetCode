# Read from the file file.txt and output all valid phone numbers to stdout.
# format matches 987-123-4567 or (123) 456-7890
grep -e "^\([0-9]\{3\}-\|([0-9]\{3\})[ ]\{1\}\)[0-9]\{3\}-[0-9]\{4\}$" file.txt
