# references:
#       https://askubuntu.com/questions/161802/how-do-i-select-a-field-column-from-the-output-of-ls-l
#       https://www.shellhacks.com/awk-print-column-change-field-separator-linux-bash/
#       https://www.thelinuxrain.com/articles/transposing-rows-and-columns-3-methods  (good article)


# Read from the file file.txt and print its transposed content to stdout.
awk '{for (i=1; i<=NF; i++) a[i,NR]=$i; max=(max<NF?NF:max)} END {for (i=1; i<=max; i++) {for (j=1; j<=NR; j++) printf "%s%s", a[i,j], (j==NR?RS:FS) }}' file.txt
