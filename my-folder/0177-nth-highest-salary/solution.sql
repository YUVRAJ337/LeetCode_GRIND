CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
    Select Distinct salary
    from Employee
    Order BY salary DESC
    LIMIT 1 OFFSET N
      

  );
END
