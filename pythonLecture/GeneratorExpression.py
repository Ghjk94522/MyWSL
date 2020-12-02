it = (len(x) for x in open('/tmp/myFile.txt'))
roots = ((x ** 0.5) for x in it)
print(next(roots))
print(next(roots))
print(next(roots))
print(next(roots))

