# How does the pipeline perform the build?
1. Build docker container
2. Run docker container
3. Build the following binaries
   1. Standard
        Does it successfully compile?
   2. Automated Testing
        Currently only runs the host side tests w/ ASAN
        @todo implement cloud setup with target compilation and hwil
    1. Static analysis
        Uses exclude paths to hide permissable warnings/errors
4. Push results to the pipeline
 
## Git branch flow for pipeline
1. master branch is used as the base
2. release
   1. Merge release into master when releasing a LTS version
3. development
   1. Merge development into release when ready
   2. Pre-requisites
      1. Pipeline success
      3. Merge/pull request 
   3. Git tag after merge request is accepted.
4. feature/myFeatureName
   1. Merge feature into development when ready
   2. Pre-requisites
      1. Pipeline success
      2. Merge/pull request
5. hotfix/myHotfixName
   1. Used as a side branch to deploy fixes to released software versions and master branches.
   2. Users should fork the branch from the version they are trying to fix
    git checkout my-git-hash-to-specific-version
   3. Implement fix
   4. Merge the fix directly to master or release
   5. Verify pipeline and perform code review


Example workflow
- Suppose Dave Krieger wants to implement a new bluetooth feature which filters out noise. He checks out a new branch
    git checkout -b feature/ble-noise-filter
- He implements the feature, writes tests, and comments the code :)
  - He runs the tests locally and everything passes
- Dave then submits a merge request from feature/ble-noise-filter into development
    git checkout development
    git merge --no-ff feature/ble-noise-filter      // *Decide about git merge vs squash vs rebase*
  - The pipeline passes the tests
- His peer/manager performs a code review and accepts the merge into the development branch. Yay!

... After many development merges have occured, it is decided that it is time to release a new software version to the public (non LTS)
    git checkout releases
    git merge targethash      // *Decide about git merge vs squash vs rebase*
- Verify pipeline passes
- Perform another code review. Decide to accept/reject the merge
- Add the tag to the successful gitmerge
    git tag -a v00.01.00 -m "Dave SW is finally released!"
    git push --tags