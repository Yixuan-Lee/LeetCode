# references:
#       https://stackoverflow.com/questions/6022384/bash-tool-to-get-nth-line-from-a-file
#       https://leetcode.com/problems/tenth-line/discuss/208499/4-ms-faster-than-100-with-tail-and-head


# Read from the file file.txt and output the tenth line to stdout.
tail -n+10 file.txt | head -1
