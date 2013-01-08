#!/bin/sh

# Keys this script replaces:
#  - GMAKE__
#  - PROJECT_PATH__

filename()
{
	echo $1 | sed 's,^.*/,,'
}

basepath()
{
	echo $1 | sed 's,^\(.*\)/.*,\1,'
}

prep_patches()
{
	local patch_file=$1
	local project_root=$2
	sed -e "s^PROJECT_PATH__^$project_root^" $patch_file > ${patch_file}.tmp
	mv ${patch_file}.tmp $patch_file
	sed -e "s/GMAKE__/gmake/g" $patch_file > ${patch_file}.tmp
	mv ${patch_file}.tmp $patch_file
}

usage()
{
	local me=`filename $0`
	echo "$me: <patch_file> <target_directory> <project_root>"
	echo "    patch_file          File containing recursive patch set to"
	echo "                        be applied against target_directory."
	echo "    target_directory    Directory where recursive 'patch'"
	echo "                        will be run using patch_file."
	echo "    project_root        Directory containing a project tree."
}

need_fullpath()
{
	echo "The full path to '$1' must be given."
}

[ $# -lt 3 ] && usage && exit 1

patch_file=$1
target_directory=$2
project_root=$3

short_patch_path=`filename $patch_file`
[ "/" != "`echo $patch_file | cut -c 1`" ] && \
	need_fullpath $short_patch_path && exit 1

tmp_patch_file=/tmp/$short_patch_path

cp $patch_file $tmp_patch_file
prep_patches $tmp_patch_file $project_root

cd $target_directory
patch -p0 < $tmp_patch_file
exitcode=$?
rm -f $tmp_patch_file

exit $exitcode
