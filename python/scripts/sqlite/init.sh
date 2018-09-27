cd sqlite
source functions.sh

export DB_PATH="../../database"
rm "$DB_PATH/db.sqlite"

sqlite3 "$DB_PATH/db.sqlite" < init.sql 
printf "\n"

./import.sh



