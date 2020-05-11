#!/bin/bash
# @file lib.sh
# @author Ashton Hellwig <ahellwig.dev@gmail.com>
# @brief Functions used by shell scripts in this project.
#

################################################################################
# Gets the path of the currently file this function is called in.
# Returns:
#   Path of the currently file this function is called in as a string.
################################################################################
function __SCRIPT_SRC_DIR__() {
  cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd
}

################################################################################
# Prints a message to stderr or std in color if color support is provided.
# Arguments:
#   -i -> Informational message printed to stdout.
#   -s -> Success message printed to stdout.
#   -e -> Error message prined to stderr.
# Outputs:
#   A message to stdout if [-i | -s] is provided. Stderr if [-e].
################################################################################
function __log_msg() {
  # Declare options
  declare _opt_USE_COLOR
  declare _opt_MESSAGE

  # Check color support
  if [ -t 1 ]; then
    local OPTIND
    declare ncolors
    ncolors=$(tput colors)

    if [ -n "$ncolors" ] && [ "$ncolors" -ge 8 ]; then
      declare -A print_colors
      print_colors=(
        ["bold"]="$(tput bold)"
        ["underline"]="$(tput smul)"
        ["standout"]="$(tput smso)"
        ["normal"]="$(tput sgr0)"
        ["black"]="$(tput setaf 0)"
        ["red"]="$(tput setaf 1)"
        ["green"]="$(tput setaf 2)"
        ["yellow"]="$(tput setaf 3)"
        ["blue"]="$(tput setaf 4)"
        ["magenta"]="$(tput setaf 5)"
        ["cyan"]="$(tput setaf 6)"
        ["white"]="$(tput setaf 7)"
      )

      _opt_USE_COLOR=true
    else
      _opt_USE_COLOR=false
    fi

    # Process Arguments
    ## Set defaults
    _opt_MESSAGE=''
    declare _opt_MSG_ERROR
    _opt_MSG_ERROR='false'
    declare _opt_MSG_INFO
    _opt_MSG_INFO='true'
    declare _opt_MSG_SUCCESS
    _opt_MSG_SUCCESS='false'

    # Parse options
    while getopts ":esim:" opt; do
      # shellcheck disable=SC2154
      case "${opt}" in
        e)
          _opt_MSG_INFO='false'
          _opt_MSG_SUCCESS='false'
          _opt_MSG_ERROR='true'
          ;;
        i)
          _opt_MSG_ERROR='false'
          _opt_MSG_SUCCESS='false'
          _opt_MSG_INFO='true'
          ;;
        s)
          _opt_MSG_ERROR='false'
          _opt_MSG_INFO='false'
          _opt_MSG_SUCCESS='true'
          ;;
        m)
          _opt_MESSAGE="${OPTARG}"
          ;;
        :)
          eprintlog "Option: ${OPTARG} requires an argument."
          ;;
        \? | *)
          return 1
          ;;
      esac
    done
    shift $((OPTIND - 1))

    if [ "$_opt_USE_COLOR" = true ]; then
      # Option: [-e|--error]
      if [ "$_opt_MSG_ERROR" = true ]; then
        echo -e "${print_colors["bold"]}[$(date +'%Y-%m-%dT%H:%M:%S%z')]:${print_colors["normal"]}${print_colors["red"]} $_opt_MESSAGE${print_colors["normal"]}" >&2
      elif [ "$_opt_MSG_INFO" = true ]; then
        echo -e "${print_colors["bold"]}[$(date +'%Y-%m-%dT%H:%M:%S%z')]:${print_colors["normal"]}${print_colors["blue"]} $_opt_MESSAGE${print_colors["normal"]}"
      elif [ "$_opt_MSG_SUCCESS" = true ]; then
        echo -e "${print_colors["bold"]}[$(date +'%Y-%m-%dT%H:%M:%S%z')]:${print_colors["normal"]}${print_colors["green"]} $_opt_MESSAGE${print_colors["normal"]}"
      fi
    else
      echo "[$(date +'%Y-%m-%dT%H:%M:%S%z')]: $_opt_MESSAGE" >&2
    fi
  fi
}
