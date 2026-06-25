/******************************************************************************
 * LEETCODE PLAYLIST BULK ADD SCRIPT
 *
 * WHAT TO CHANGE:
 *
 * 1. favoriteSlug
 *    Get it from your playlist URL:
 *
 *    https://leetcode.com/problem-list/dr614ycm/
 *                                      ^^^^^^^^
 *
 *    Example:
 *    const favoriteSlug = "dr614ycm";
 *
 * ---------------------------------------------------------------------------
 *
 * 2. urls
 *    Paste any number of LeetCode problem URLs here.
 *
 *    Example:
 *
 *    const urls = `
 *    https://leetcode.com/problems/two-sum
 *    https://leetcode.com/problems/3sum
 *    https://leetcode.com/problems/house-robber
 *    `;
 *
 * ---------------------------------------------------------------------------
 *
 * HOW TO USE:
 *
 * 1. Login to LeetCode
 * 2. Open the target playlist
 * 3. Press F12
 * 4. Open Console tab
 * 5. Paste this script
 * 6. Press Enter
 * 7. Wait until "Done" appears
 * 8. Refresh the playlist page
 *
 ******************************************************************************/

const favoriteSlug = "PUT_PLAYLIST_SLUG_HERE";

const urls = `
PASTE_PROBLEM_URLS_HERE
`;

/******************************************************************************
 * DO NOT MODIFY ANYTHING BELOW THIS LINE
 ******************************************************************************/

const questionSlugs = urls
  .trim()
  .split("\n")
  .map(x => x.trim())
  .filter(Boolean)
  .map(url => {
    const match = url.match(/\/problems\/([^/]+)/);
    return match ? match[1] : null;
  })
  .filter(Boolean);

async function addBatch(slugs) {
  const csrf =
    document.cookie.match(/csrftoken=([^;]+)/)?.[1];

  const response = await fetch("/graphql/", {
    method: "POST",
    credentials: "include",
    headers: {
      "content-type": "application/json",
      "x-csrftoken": csrf,
      "x-operation-name": "batchAddQuestionsToFavorite"
    },
    body: JSON.stringify({
      operationName: "batchAddQuestionsToFavorite",
      query: `
        mutation batchAddQuestionsToFavorite(
          $favoriteSlug: String!,
          $questionSlugs: [String]!
        ) {
          batchAddQuestionsToFavorite(
            favoriteSlug: $favoriteSlug
            questionSlugs: $questionSlugs
          ) {
            ok
            error
          }
        }
      `,
      variables: {
        favoriteSlug,
        questionSlugs: slugs
      }
    })
  });

  return response.json();
}

(async () => {

  console.log(
    `Found ${questionSlugs.length} questions.`
  );

  // Process in batches of 20
  // Helps avoid request-size limits.
  for (let i = 0; i < questionSlugs.length; i += 20) {

    const batch = questionSlugs.slice(i, i + 20);

    const result = await addBatch(batch);

    console.log(
      `Batch ${Math.floor(i / 20) + 1}/${Math.ceil(questionSlugs.length / 20)}`,
      result
    );

    // Small delay between requests
    await new Promise(resolve => setTimeout(resolve, 500));
  }

  console.log("Done");
})();