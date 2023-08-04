import os

# add  all rs file in src/leetcode to mod.rs

dir = "src/leetcode"
files = os.listdir(dir)

# rename all filename to snake case not only rust file
# for file in files:
#     # 如果包含大写字母，说明是驼峰命名，先添加下划线，再全部转小写, 不仅仅只是改成小写
#     if file != file.lower():
#         # 从后往前找到大写字母的位置，添加下划线
#         newfile = file
#         for i in range(len(file) - 1, -1, -1):
#             if file[i].isupper():
#                 newfile = newfile[:i] + "_" + file[i:]
#         os.rename(os.path.join(dir, file), os.path.join(dir, newfile.lower()))
#     else:
#         os.rename(os.path.join(dir, file), os.path.join(dir, file.replace("-", "_")))

files = os.listdir(dir)
with open("src/leetcode/mod.rs", "w") as f:
    for file in files:
        if file == "mod.rs":
            continue
        if file.endswith(".rs"):
            mod = "___" + file[:-3]
            f.write(f'#[path = "{file}"]\npub mod {mod};\n')

    # f.write("\n")
    # for file in files:
    #     if file.endswith(".rs"):
    #         f.write("pub use " + file[:-3] + "::*;\n")
