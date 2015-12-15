This is a DM's toolkit for the pathfinder RPG. 

requires 
a c++ compiler such as g++
mysql libraries for C++ such as libmysql++3

compiling looks like this: 
gloom@green:~/Code/pathf$ g++ dungeonmaster.cpp -I/usr/include/mysql++/ -I/usr/include/mysql/ -lmysqlpp -o dm.out


reads bestiary and trap information from a database with these tables: : 

MariaDB [pathf_DB]> describe monsters;
+------------------+-------------+------+-----+---------+-------+
| Field            | Type        | Null | Key | Default | Extra |
+------------------+-------------+------+-----+---------+-------+
| name             | varchar(20) | YES  |     | NULL    |       |
| CR               | int(11)     | YES  |     | NULL    |       |
| XP               | int(11)     | YES  |     | NULL    |       |
| perception_bonus | int(11)     | YES  |     | NULL    |       |
| environment      | varchar(10) | YES  |     | NULL    |       |
| groups           | varchar(30) | YES  |     | NULL    |       |
+------------------+-------------+------+-----+---------+-------+

MariaDB [pathf_DB]> describe traps;
+--------------+-------------+------+-----+---------+-------+
| Field        | Type        | Null | Key | Default | Extra |
+--------------+-------------+------+-----+---------+-------+
| name         | varchar(30) | YES  |     | NULL    |       |
| CR           | int(11)     | YES  |     | NULL    |       |
| XP           | int(11)     | YES  |     | NULL    |       |
| perceptionDC | int(11)     | YES  |     | NULL    |       |
| disableDC    | int(11)     | YES  |     | NULL    |       |
+--------------+-------------+------+-----+---------+-------+

======================
:Useful mysql queries: 
======================

--------------
- Populating -
--------------

MariaDB [pathf_DB]> INSERT INTO traps VALUES ('Fireball Trap', 5, 1600, 28, 28);

-------------
- Selecting -
------------- 

MariaDB [pathf_DB]> select * from traps where CR <= 1;

MariaDB [pathf_DB]> select * from `monsters` where `groups` like '%goblin%';

