# Write your MySQL query statement below
Select MAX(salary) as SecondHighestSalary
from employee where salary < (
    Select Max(Distinct salary) from employee
)