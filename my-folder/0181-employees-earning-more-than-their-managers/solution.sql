# Write your MySQL query statement below
Select name AS Employee
From Employee e1
Where salary > (
    Select salary
    from Employee e2
    Where e2.id=e1.managerId
);
