import json

if __name__ == '__main__':
    file_name = 'problems.json'
    info_lst = []
    with open(file_name) as fh:
        for info in json.load(fh)['stat_status_pairs']:
            item = {
                'stat': {
                    'frontend_question_id': info['stat']['frontend_question_id'],
                    'question__title': info['stat']['question__title'],
                    'question__title_slug': info['stat']['question__title_slug'],
                },
                'difficulty': {},
            }
            if not info['paid_only']:
                item['paid_only'] = info['paid_only']
                item['difficulty']['level'] = info['difficulty']['level']
                info_lst.append(item)

    with open('problems.json', 'w') as fh:
        info_all = {
            'stat_status_pairs': info_lst,
        }
        json.dump(info_all, fh)
