```cpp
ReUnit reNode = ReUnit::orGroup(
        {ReUnit::unit("a") ,
            ReUnit::concatGroup({
                ReUnit::star(ReUnit::unit("b")),
                ReUnit::unit("d"),
                ReUnit::optional(ReUnit::unit("c")),
            })
        });
cout << reNode.getExpression() << endl;
NfaBuilder builder(reNode);
DfaBuilder reBuilder = builder.compileToNfa();
ReMatcher reMatcher = reBuilder.compileToDfa();
```