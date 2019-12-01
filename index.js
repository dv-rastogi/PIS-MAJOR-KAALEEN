const Octokit = require('@octokit/rest')
const fastify = require('fastify')()
const fetch = require('node-fetch')

const GIST_ID = 'f2b786a8b785555b07894d0b649999b0'
const GH_TOKEN = '711114430a453cbd1e5b4492a94d23d266a6800c'

fastify.get('/set', async (req, reply) => {
	const octokit = new Octokit({ auth: `token ${GH_TOKEN}` }) // Instantiate Octokit
	const gist = await octokit.gists.get({ gist_id: GIST_ID }) // get the gist

	console.log(req)

	await octokit.gists.update({
		gist_id: GIST_ID,
		files: {
			'kaaleen.txt': {
				filename: 'kaaleen.txt',
				content: req.query.n.toString()
			}
		}
	})

	reply.send('done')
})

fastify.get('/get', async (req, reply) => {
	const n = await fetch(`https://api.github.com/gists/${GIST_ID}`)
		.then(res => res.json())
		.then(res => res.files['kaaleen.txt'])
		.then(res => Number(res.content))
	reply.send(n)
})

fastify.listen(process.env.PORT || 3000, err => {
	if (err) throw err
})
