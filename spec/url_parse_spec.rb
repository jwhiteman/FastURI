require "spec_helper"

describe URLParse do
  describe "#parse" do
    it "parses relative netpaths" do
      up = URLParse.new("//foo-bar-baz")

      expect(up.parse).to eq({uri: "//foo-bar-baz"})
    end

    it "parses relative netpaths with domain labels" do
      up = URLParse.new("//foo.bar.baz")

      expect(up.parse).to eq({uri: "//foo.bar.baz"})
    end
  end
end

