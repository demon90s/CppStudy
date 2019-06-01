练习15.31：已知s1、s2、s3和s4都是string，判断下面的表达式分别创建了什么样的对象：

(a) Query(s1) | Query(s2) & ~Query(s3);

(b) Query(s1) | (Query(s2) & ~Query(s3));

(c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));

---

Query(s)创建了一个WordQuery对象。

|操作创建了OrQuery对象，~操作创建了NotQuery对象，&操作创建了AndQuery对象。
