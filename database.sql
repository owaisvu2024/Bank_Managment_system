create database bank;
use bank;


create table manager(
username varchar(15) ,
password varchar(15) unique 
);

create table employee1(
account_no int auto_increment primary key,
username varchar(15),
pin int unique,
balance float
);
alter table employee1 auto_increment = 1001;
select * from employee1;
select * from manager;