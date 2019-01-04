# references:
#       https://stackoverflow.com/questions/6022384/bash-tool-to-get-nth-line-from-a-file


# Read from the file file.txt and output the tenth line to stdout.
perl -wnl -e '$.== 10 && print && exit;' file.txt
