# Write your MySQL query statement below
SELECT
p.firstName,
p.lastName,
a.city,
a.state
From
person p
left join
Address a ON p.personId = a.personID;
