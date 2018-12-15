练习12.21：也可以这样编写StrBlobPtr的deref成员：

```
std::string & deref() const
{
	return (*check(curr, "deference past end"))[curr];
}
```

你认为哪个版本更好？为什么？

---

原版本更好，因为代码更清晰。
