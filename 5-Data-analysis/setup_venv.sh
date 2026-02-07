#!/usr/bin/env bash
# Create a virtual environment and install dependencies for explore-data.ipynb.
# Run from the Data-analysis directory: ./setup_venv.sh
# Then activate with: source .venv/bin/activate

set -e
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR"

VENV_DIR=".venv"
if [[ ! -d "$VENV_DIR" ]]; then
    echo "Creating virtual environment in $VENV_DIR ..."
    python3 -m venv "$VENV_DIR"
else
    echo "Virtual environment already exists at $VENV_DIR"
fi

echo "Installing dependencies (pandas, numpy, ipykernel) ..."
"$VENV_DIR/bin/pip" install --upgrade pip
"$VENV_DIR/bin/pip" install pandas numpy ipykernel

# Register the venv as a Jupyter kernel so Cursor/VS Code can use it for the notebook
"$VENV_DIR/bin/python" -m ipykernel install --user --name=schur-data-analysis --display-name "Python (Schur data analysis)"

echo ""
echo "Done. To activate the environment in this terminal, run:"
echo "  source $VENV_DIR/bin/activate"
echo ""
echo "Select the kernel 'Python (Schur data analysis)' to run explore-data.ipynb."
