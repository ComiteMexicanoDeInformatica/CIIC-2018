import logging
import os
import sys
import subprocess
import json

def problems():
    logger = logging.getLogger(__name__)
    logging.basicConfig(format='%(asctime)s: %(message)s', level=logging.INFO)

    env = os.environ

    logger.info('Loading problems...')

    with open('problems.json', 'r') as p:
        config = json.loads(p.read())

    problems = config['problems']

    if '--all' in sys.argv:
        logger.info('Loading everything as requested.')
        return problems
    elif ('CIRCLE_BRANCH' in env and
          env['CIRCLE_BRANCH'] in ['master', 'public']):
        logger.info('Loading all problems for special branch.')
        return problems

    problems = []

    logger.info('Loading git diff.')

    git = subprocess.Popen(
        ["git", "diff", "--name-only", "--diff-filter=AMDR", 'origin/master...HEAD'],
        stdout = subprocess.PIPE)

    git.wait()
    changes = str(git.stdout.read())

    for p in config['problems']:
        path = p['path']
        title = p['title']

        logger.info('Loading {}.'.format(title))

        if path in changes:
            problems.append(p)
        else:
            logger.info('No changes. Skipping.')

    return problems
