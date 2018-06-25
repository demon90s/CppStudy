练习15.34：针对图15.3（第565页）构建的表达式：

(a) 列举出在处理表达式的过程中执行的所有构造函数。

(b) 列举出cout<<q所调用的rep。

(c) 列举出q.eval()所调用的eval。

---

**(a)**

- Query::Query(const std::string &s)

- WordQuery::WordQuery(const std::string &s)

- AndQuery::AndQuery(const Query &left, const Query &right)

- BinaryQuery::BinaryQuery(const Query &l, const Query &r, std::string s)

- Query::Query(std::shared_ptr<Query_base> query)

- Query::Query(const Query&)（Query合成的拷贝构造函数）

- OrQuery::OrQuery(const Query &left, const Query &right)

**(b)**

Query::rep -> Query_base::rep（动态绑定到派生类对象的rep上面）

**(c)**

Query_base::eval（动态绑定到派生类对象的rep上面）
