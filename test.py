test = {'abc': 1, 'def': 2, 'jiji': 3, 'ghi': 4}
print(type(test))
test = sorted(test)
print(type(test))
for i in range(len(test)):
    print(test[i])
