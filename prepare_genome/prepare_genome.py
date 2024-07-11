# Unzips every .gz file in a directory.

import os
import sys
import gzip
import io


def main():

    if len(sys.argv) > 1:
        read_dir = sys.argv[1]
    else:
        print("Usage: python prepare_genome.py <directory>")
        sys.exit(1)

    try:
        files = os.listdir(read_dir)
        for filename in files:
            if filename.endswith(".gz"):
                file_path = os.path.join(read_dir, filename)
                print("Processing file: ", file_path)
                with gzip.open(file_path, 'rb') as ip:
                    with io.TextIOWrapper(ip, encoding='utf-8') as decoder:
                        with open(file_path[:-3] + ".cpm1", 'w') as f_out:
                            for line in decoder:
                                if not line.startswith('>'):
                                    # Strip trailing whitespace characters including newline
                                    line = line.rstrip()
                                    f_out.write(line)
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    main()
    print("Finished!")

