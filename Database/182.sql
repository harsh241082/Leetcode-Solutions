select distinct p1.email as Email
from Person p1 join Person p2 on p1.id != p2.id
where p1.email = p2.email;

SELECT email as Email
FROM Person
GROUP BY email
where count(id) > 1;