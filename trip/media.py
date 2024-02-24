from math import ceil

def media(a):
    mean = 0
    count = 0
    for i in a:
        if i == "":
            continue
        count += 1
        mean += float(i)
    mean /= count
    print(f"{mean:.2f}")

def process_file(file_path, starts_with):
    a = []
    with open(file_path, "r", encoding="utf-8") as file:
        lines = file.readlines()
        for line in lines:
            if line.startswith(starts_with):
                a = line.split("|")
    numeric_data = [item for item in a if item.replace(".", "", 1).isdigit()]
    return numeric_data

arc = "archive.md"

names = [
    "|Lake house|",
    "|Paraíso|",
    "|Pedra|",
    "|Banheira|",
    "|Pier|",
]

for name in names:
    processing = process_file(arc, name)
    #print(processing)
    media(processing)