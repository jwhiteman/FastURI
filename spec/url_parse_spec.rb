require "spec_helper"

describe URLParse do
  let(:parser) do
    URLParse.new("http://foo.com/posts?id=30&limit=5#time=1305298413")
  end

  describe "#parse" do
    it "parses" do
      parser.parse
    end
  end
end

