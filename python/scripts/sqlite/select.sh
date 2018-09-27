export color='\033[43m\033[30m'
export nocolor='\033[0m'

current_date_time="`date +%Y-%m-%d-%H-%M-%S`";
printf "\033[42m\033[30m%-6s\033[0m%s\n" "- sqlite [$current_date_time]";

printf "" > file.sql
printf ".header on\n" >> file.sql
printf ".mode column\n" >> file.sql

printf ".print \n" >> file.sql
printf ".print ${color}tblmod${nocolor}\n" >> file.sql
printf "select * from tblmod;\n" >> file.sql

printf ".print \n" >> file.sql
printf ".print ${color}tblmodoption${nocolor}\n" >> file.sql
printf "select * from tblmodoption;\n" >> file.sql

printf ".print \n" >> file.sql
sqlite3 "/mnt/dev/wootz-satcom/develop/build/temp/linux/database/epaf_database.sqlite3" < file.sql 

printf "\n"



