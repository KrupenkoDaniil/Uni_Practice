# Task 1

```bash
b factorial:16
info locals
```

# Task 2, 3

```bash
break string_read
break string_print
run
# inside string_read
where
info locals
finish
# back in the caller after string_read returned
where
continue
# inside string_print, at the entry
where
info locals
finish
# back in the caller after string_print returned
where
continue
```

```

```
