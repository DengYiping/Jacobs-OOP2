import os
import sys

SIGNATURE = '/*\n    JTSK-320111\n    {}\n    Yiping Deng\n    y.deng@jacobs-university.de\n*/\n'
def append_signature(f_name, dic):
    full_path = dic + f_name
    sign = SIGNATURE.format(f_name)
    data = ''
    with open(full_path, 'rb') as original: data = original.read()
    with open(full_path, 'wb') as modified: modified.write(str.encode(sign) + data)

if __name__ == '__main__':
    if len(sys.argv) <= 1:
        print("please specify the directory to compile")
        exit()

    dic_name = sys.argv[1]
    if dic_name[-1] != '/':
        dic_name = dic_name + '/'
    files = os.listdir(dic_name)
    for f in files:
        append_signature(f, dic_name)
