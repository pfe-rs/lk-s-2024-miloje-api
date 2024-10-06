import os
import sys

sys.path.insert(0, os.path.abspath("../api"))

project = "MILOJE"
copyright = "2024, PFE"  # noqa: A001
author = "PFE"

extensions = ["sphinx.ext.autodoc"]

templates_path = ["_templates"]
exclude_patterns = []

html_theme = "alabaster"
html_static_path = []
