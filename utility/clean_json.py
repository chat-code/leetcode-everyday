import json
import argparse

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--input", type=str, help="The JSON file to clean")
    parser.add_argument(
        "--output",
        type=str,
        help="The JSON file to output",
        default="problems.json",
        required=False,
    )
    args = parser.parse_args()

    file_name = args.input
    output_file_name = args.output

    info_lst = []
    with open(file_name) as fh:
        for info in json.load(fh)["stat_status_pairs"]:
            item = {
                "stat": {
                    "frontend_question_id": info["stat"]["frontend_question_id"],
                    "question__title": info["stat"]["question__title"],
                    "question__title_slug": info["stat"]["question__title_slug"],
                },
                "difficulty": {},
            }
            if not info.get("paid_only", None):
                item["difficulty"]["level"] = info["difficulty"]["level"]
                info_lst.append(item)

    with open(output_file_name, "w") as fh:
        info_all = {
            "stat_status_pairs": info_lst,
        }
        json.dump(info_all, fh, indent=4)
        fh.write("\n")
